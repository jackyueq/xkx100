//Edited by fandog, 01/31/2000

inherit ROOM;
void create ()
{
	set ("short", "����");
	set ("long", @LONG
����֪��������Ļ��ԡ��������м�����ɫ�ر��޵Ļƻ�����Щ
���Ļ���Ƶ������һ����������������������Ӻ���ɻ���ֻ��û��
����ô�󡣱�����֪�����˵��鷿���ϱ��ǿ�����������֪�����˺ͼ�
���ס����
LONG);
	set("outdoors", "jiangling");
	set("exits", ([ 
		"north" : __DIR__"shufang",
		"south" : __DIR__"keting",
		"east"  : __DIR__"dongxiang",
		"west"  : __DIR__"datang",
	]));
	set("objects", ([
		__DIR__"obj/jinboxunhua" : 2,
	]));

	set("coor/x", -1488);
	set("coor/y", -2030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
