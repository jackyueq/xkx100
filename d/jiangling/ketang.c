//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "����");
	set ("long", @LONG
�������������ؿ��˵�С���á��м�һ��СԲ��ľ���ϣ�������
һ����ϯ�����ſ����������ε��⣬���Կ�����԰�Ĵ�ɫ��
LONG);
	set("exits", ([
		"up"     : __DIR__"donglou",
		"west"   : __DIR__"zoulang1",
		"east"  : __DIR__"huayuan",
	]));
	set("objects", ([
		__DIR__"obj/babao" : 1,
		__DIR__"obj/longfeng" : 1,
	]));
  
	set("coor/x", -1487);
	set("coor/y", -2040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
