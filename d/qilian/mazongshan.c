// Room: /d/qilian/mazongshan.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "����ɽ");
	set("long", @LONG
����ɽ״��������ɽ���೤��ɽ��᯲�룬����Ұ��֮�ס�����
���ǽ������ĳ϶�����ɽ�ߣ��ɵñ��ض��飬����Ϊ�����ʽ�ɽ�ߣ���
��������
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"southdown" : __DIR__"niaojutai",
		"west"      : __DIR__"qilianshan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -11000);
	set("coor/y", 3000);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}