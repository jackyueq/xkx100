// Room: /d/nanshaolin/lwc3.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡���ǧ��
�Ĳ�̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬��ʮ����ɮ��������ϰ�似��������
�������һ���䳡��
LONG );
	set("exits", ([
		"east"  : __DIR__"lwc2",
		"west"  : __DIR__"lwc4",
		"south" : __DIR__"lwc5",
	]));
	set("objects",([
		__DIR__"obj/zhuang" : 1,
	]));
	set("outdoors", "nanshaolin");
	set("coor/x", 1780);
	set("coor/y", -6230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

