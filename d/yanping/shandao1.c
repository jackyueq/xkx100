// Room: /d/yanping/shandao1.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
������խխ������ɽС���ϣ�ɽ·��᫣�����ɭɭ�����г���Ұ��
��û����ν��������������ѡ����ϲ����ۡ�������ų���Ϫ��������
����ڶ��ϵ�����ɽ�ˡ�
LONG );
	set("exits", ([
		"northup" : __DIR__"erbapu",
		"southup" : __DIR__"yidao1",
		"west"    : "/d/wuyi/wuyigong",
	]));
	set("no_clean_up", 0);
	set("outdoors", "jiangnan");
	set("coor/x", 1500);
	set("coor/y", -5000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
