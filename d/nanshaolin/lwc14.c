// Room: /d/nanshaolin/lwc14.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡���ǧ��
�Ĳ�̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬���䳡����������һ������
���ɵ�����ͭ�ˣ�һЩ׳��ɮ�����������������С�
LONG );
	set("exits", ([
		"east" : __DIR__"lwc13",
		"south" : __DIR__"lwc16",
	]));
	set("objects",([
		__DIR__"obj/tong-ren" : 1,
	]));
	set("outdoors", "nanshaolin");
	set("coor/x", 1850);
	set("coor/y", -6230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

