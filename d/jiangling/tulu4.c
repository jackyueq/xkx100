//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "��ɽС·");
	set("long", @LONG
���߶��ǻ�ɽ����ʯ��ᾣ���������ͩ�����Ͳ���Ҳ�����ֵġ���
�߻�ɽ֮�У���һ�����˴�����֪��ɽ������������ɽ�£�����һ����
ɽ��ǰ��
LONG );
	set("exits", ([
		"eastdown"  : __DIR__"maxipu",
		"enter"     : __DIR__"dashandong",
	]));
	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1620);
	set("coor/y", -2210);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}