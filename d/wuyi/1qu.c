// Room: /d/wuyi/1qu.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "һ��");
	set("long", @LONG
������ɽ��ת�����ˮ������������������³���������ɽ����Ϫ
�ˡ�Ϫ�������ǵ���ʥ�����Ĺ����ϰ��Ǵ�С�����ҡ�Ϫˮ����������
ƽ������ȥ�������Ϫ�����䡶�������衷Ի��������ɽ�������飬ɽ
�º��������塣��ʶ���������������������������һ��Ϫ���ϵ�����
�ͤ��Ӱպ�紨������һ������Ϣ������ǧ�������̡�������
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : __DIR__"2qu",
		"north"     : __DIR__"wuyigong",
		"northwest" : __DIR__"path1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1400);
	set("coor/y", -5010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

