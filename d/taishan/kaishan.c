// Room: /d/taishan/kaishan.c
// Last Modified by winder on Aug. 25 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
����ɽ�����߸�֮�ϣ�˫�¼е����ɳ����ţ�������ɽ��Ϊ��Ǭ¡ĩ
��Ľ��̵�ʱ���١��������̩ɽʮ���̵���㡣�˴����ϣ�ֱ�����ţ�
����֮Ϊ����ʮ���̡���
LONG );
	set("exits", ([
		"northup"   : __DIR__"man18",
		"southdown" : __DIR__"duisong",
	]));
	set("objects", ([
		CLASS_D("taishan")+"/first" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 360);
	set("coor/y", 710);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}
