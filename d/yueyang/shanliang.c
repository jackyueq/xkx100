// Room: /d/yueyang/shanliang.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "Сɽ��");
	set("long", @LONG
��վ��һ��Сɽ���ϣ�Զ��������㣬������˸����鳿������
�����Ӷ����������������ݰ�ľ�ɽ�������������궴ͥ�����У�����
��������һ��������Դ��⡣
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"northdown" : __DIR__"xiaolu4",
		"southdown" : __DIR__"erfeimu",
	]));
	set("coor/x", -1670);
	set("coor/y", 2310);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
