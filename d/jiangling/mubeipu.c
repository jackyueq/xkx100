//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "Ĺ����");
	set ("long", @LONG
˵��һ�ҵ��̣���ʵ����һ������������ʯ�����𾢵������ʯ����
������ݳ�����ɥ�µ��˼һ��治�٣����ײġ�Ĺ���ı�æ�������ˡ�
�Ĵ��ѷ��˲���δ�깤��Ĺ����һ���๤����Ѳ�ӡ�
LONG);
	set("exits", ([ 
		"east" : __DIR__"xijie1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1510);
	set("coor/y", -1110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
