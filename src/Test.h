//
// Created by Kiana on 2024/5/1.
//

#ifndef SOUND_PLAYBACK_TEST_H
#define SOUND_PLAYBACK_TEST_H

#include <QWidget>
#include <QIODevice>
#include <QAudioInput>
#include <QAudioDeviceInfo>
#include <QAudioFormat>
#include <QDebug>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class Test; }
QT_END_NAMESPACE

class Test : public QWidget {
Q_OBJECT

public:
    explicit Test(QWidget *parent = nullptr);

    void startRecording();

    void stopRecording();

    ~Test() override;

private slots:
    void onStateChanged(QAudio::State state);

    void onReadyRead();

private:
    Ui::Test *ui;
    QAudioInput *audioInput;
    QFile *outputFile;
};


#endif //SOUND_PLAYBACK_TEST_H
