//Edited by fandog, 02/18/2000
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
���Ǿ��ݳǵĶ��š����Ų���Ҳ���˿��ء������߳��ǣ���һ��
�������۵�ɽ����
LONG );
	set("outdoors", "jiangling");
	set("exits", ([
               "south" : __DIR__"shandao5",
               "north" : __DIR__"dongjie2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1470);
	set("coor/y", -2040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}