//
// Created by Kiana on 2024/5/1.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Test.h" resolved

#include "Test.h"
#include "ui_Test.h"


Test::Test(QWidget *parent) :
        QWidget(parent), ui(new Ui::Test) {
    ui->setupUi(this);
    // 设置音频格式
    QAudioFormat format;
    format.setSampleRate(44100); // 采样率
    format.setChannelCount(1); // 通道数
    format.setSampleSize(16); // 样本大小
    format.setCodec("audio/pcm"); // 编码格式
    format.setByteOrder(QAudioFormat::LittleEndian); // 字节序
    format.setSampleType(QAudioFormat::SignedInt); // 样本类型

    // 获取音频输入设备
    QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
    if (!info.isFormatSupported(format)) {
        qDebug() << "Default format not supported - trying to use nearest.";
        format = info.nearestFormat(format);
    }

    // 创建音频输入
    audioInput = new QAudioInput(info, format, this);
    connect(audioInput, &QAudioInput::stateChanged, this, &Test::onStateChanged);

    // 准备写入文件
    outputFile = new QFile("output.wav");
    if (!outputFile->open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qDebug() << "Unable to open output file";
        return;
    }

    // 连接readyRead信号以处理音频数据
    //connect(audioInput, &QAudioInput::readyRead, this, &Test::onReadyRead);
}

void Test::startRecording() {
    if (audioInput->state() != QAudio::ActiveState) {
        audioInput->start(outputFile);
    }
}

Test::~Test() {
    delete ui;
}

void Test::stopRecording() {
    if (audioInput->state() == QAudio::ActiveState) {
        audioInput->stop();
    }
}

void Test::onStateChanged(QAudio::State state) {
    qDebug() << "Audio state changed:" << state;
}

void Test::onReadyRead() {

}
