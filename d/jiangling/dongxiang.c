//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "���᷿");
	set ("long", @LONG
����֪�����˺ͼҾ���ӵĴ���������һ�ŵ񻨴�ľ�������϶ѵ�
�Ž������廨��ͷ��������һ�����ȣ�������һ�����ԣ���Լ��������
�������㡣
LONG);
	set("exits", ([
		"north" : __DIR__"zoulang",
		"west"  : __DIR__"huapu",
	]));
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("sleep_room", 1); 
	set("coor/x", -1480);
	set("coor/y", -2030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}