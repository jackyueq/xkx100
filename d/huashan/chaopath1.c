// Roon: chaoyangpath1.c ������С·
//Date: Oct. 2 1997 by Venus

inherit ROOM;

void create()
{
	set("short","������С·");
	set("long",@LONG
�����ǳ�����С·��ɽ�ƶ��ͣ�����������ȣ�һ��С�Ķ������
��ȥ��
LONG);
	set("outdoors", "huashan");
	set("exits",([ /* sizeof() == 1 */
		"northeast": __DIR__"chaopath2",
		"southeast": __DIR__"square",
	]));
	set("objects", ([
		"/clone/medicine/vegetable/jinyinhua" : random(2),
	]));
	set("coor/x", -870);
	set("coor/y", 210);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
