// Room: /d/yanping/mangdangshan.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "ã��ɽ");
	set("long", @LONG
ã��ɽ�������磬������ѡ����ƾ��죬������ʯ�ڶ��͡������
���£�ɽ��СϪ���ڵ��������ͳ��������ڶ���ǰ����Ϊ�ٲ�����Զ��
���в�ʱ������������������������Ĳ��������������ľ�����Զ�ĸ�
������Ŀ�Ĺˣ��������̾㾲����ɽ��ɫ���پ����ؿ�����������ˬ��
LONG );
	set("exits", ([
		"east" : __DIR__"gubao",
	]));
	set("outdoors", "yanping");
	set("no_clean_up", 0);
	set("coor/x", 1480);
	set("coor/y", -6110);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
