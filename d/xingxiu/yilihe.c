// Room: /d/xingxiu/yilihe.c
// Last Modified by winder on Apr. 25 2001

inherit ROOM;
void quarter_pass();

void create()
{
	set("short", "�����");
	set("long", @LONG
����ӣ�λ����������ϣ�����ɽ���ܻ����µ�ѩˮ�㼯���ɡ���
�����������ö�������ǣ���ӱ���ˮ��Ϊ��һ�ε���;����׼������ˮ
����͸�������ϥ��
LONG);

	set("outdoors", "xiyu");
	set("exits", ([
		"southwest" : __DIR__"shanjiao",
		"north"     : __DIR__"yiligate",
	]));

	set("objects", ([
		 __DIR__"npc/yang" : 1,
		 __DIR__"npc/hgirl" : 1,
	]));
	set("coor/x", -39000);
	set("coor/y", 11000);
	set("coor/z", 0);
	setup();
//	replace_program(ROOM);
}
#include "/d/xingxiu/job2.h";

