// Room: /d/nanshaolin/lwc2
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡���ǧ��
�Ĳ�̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬���䳡����������һ������
���ɵ�ľ�ˣ�һЩ����ɮ������Χ����������
LONG );
	set("exits", ([
		"west"  : __DIR__"lwc3",
		"south" : __DIR__"lwc1",
	]));
	set("objects",([
		__DIR__"obj/mu-ren" : 5,
	]));
	set("outdoors", "nanshaolin");
	set("coor/x", 1790);
	set("coor/y", -6230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

