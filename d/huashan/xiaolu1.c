//Room: xiaopath1.c Сɽ·
//Date: Oct. 2 1997 by Venus

inherit ROOM;

void create()
{
	set("short","Сɽ·");
	set("long",@LONG
�����ǻ�ɽ��һ��Сɽ·�����ƽ�Ϊƽ�������������ط���ô��
����������������ܾ����ĵģ�������߽���һ��������Դ��
LONG);
	set("outdoors", "huashan");
	set("exits",([ /* sizeof() == 1 */
		"southwest" : __DIR__"yunu",
		"northeast" : __DIR__"xiaolu2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -850);
	set("coor/y", 200);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
