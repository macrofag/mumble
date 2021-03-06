/* Copyright (C) 2005-2011, Thorvald Natvig <thorvald@natvig.com>

   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

   - Redistributions of source code must retain the above copyright notice,
     this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.
   - Neither the name of the Mumble Developers nor the names of its
     contributors may be used to endorse or promote products derived from this
     software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef MUMBLE_MUMBLE_USERINFORMATION_H_
#define MUMBLE_MUMBLE_USERINFORMATION_H_

#include <QtNetwork/QSslCertificate>

#include "Message.h"

#include "ui_UserInformation.h"
#include "ClientUser.h"

namespace MumbleProto {
class UserStats;
}

class QTimer;


class UserInformation : public QDialog, Ui::UserInformation {
	private:
		Q_OBJECT
		Q_DISABLE_COPY(UserInformation)
	protected:
		bool bRequested;
		unsigned int uiSession;
		QTimer *qtTimer;
      ClientUser *currentUser;
		QList<QSslCertificate> qlCerts;
		static QString secsToString(unsigned int secs);
		QFont qfCertificateFont;
	protected slots:
		void tick();
		void on_qpbCertificate_clicked();
      void gainChanged(int);
      void gainCheckClicked(int);
	public:
		UserInformation(const MumbleProto::UserStats &msg, QWidget *p = NULL);
		void update(const MumbleProto::UserStats &msg);
		unsigned int session() const;
};

#endif
