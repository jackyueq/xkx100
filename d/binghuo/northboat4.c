// Room: /binghuo/northboat4.c
// Date: Oct.28 1999 by Winder
#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", "�Ʒ���");
	set("long", @LONG
�����ں�����������Ư���ţ�û�з���Ҳû�н��������εؿ���
��ԽƯԽ��������ˮ�׽Ծ�����������֧�룬�Ҳ��̶ã�ûһ������
�ĵط��ˡ�
LONG );
	set("no_sleep_room",1);
	set("outdoors", "binghuo");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

