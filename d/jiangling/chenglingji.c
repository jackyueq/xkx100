//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{

	set ("short", "�����");
	set ("long", @LONG
�����Ƕ�ͥ���볤����ϴ���ˮ�����ãã��������ֻŸ���Ĵ�
�ų��ʱ��ˮ����Ӷ�����
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"west" : __DIR__"dangyangqiao",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1490);
	set("coor/y", -2070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
