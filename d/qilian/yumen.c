// Room: /d/qilian/yumen.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������������һ������վ�������ɹţ������ຣ���������ں�����
��������ԭ��������һ��Ҫ���������ǹ����������������Źء�
LONG );
	set("outdoors", "qilian");
	set("no_clean_up", 0);
	set("exits", ([
		"southwest" : "/d/xingxiu/jiayuguan",
		"north"     : __DIR__"halahu",
	]));
	set("coor/x", -17000);
	set("coor/y", 1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}