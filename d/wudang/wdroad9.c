// wdroad9.c ����·
// Date: Feb.12 1998 By Java

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
������һ����������Ļ���·�ϣ���������ɭɭ�����֡������Ǻ�
�����磬��˵���������˳�û�����ɾ���������ȥ�������ꡣ
LONG );
	set("outdoors", "sanbuguan");
	set("exits", ([
		"northwest" : __DIR__"sanbuguan",
		"south"     : __DIR__"wdroad10",
		"southeast" : "/d/jiangling/tulu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -2000);
	set("coor/y", 800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
