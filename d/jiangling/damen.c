//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "����");
	set ("long", @LONG
���Ǿ��ݴ���������������������ɽ��ס������ֵ����Ӣ����ʮ��
�٣���������ҵƽ�ʣ�ǰ�����ٵĿ���̸Ц���߽������������ִ�
��ӭ����������
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"east"  : __DIR__"dating",
		"west"  : __DIR__"xijie4",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1490);
	set("coor/y", -2040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
