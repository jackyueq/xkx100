// Room: /d/wuyi/3qu.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
Ϫˮ�ڻ����д�ת����͸��ˮ�У�����Ҵҡ�������Կ�����ط�
��ֱ���ұںͱڶ��еĵ��ݡ����䡶�������衷Ի������������������
�ִ�����֪ͣ�������ꣿɣ�ﺣˮ��������ĭ��Ƹ�������������
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast" : __DIR__"2qu",
		"southwest" : __DIR__"4qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1380);
	set("coor/y", -5000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

