//  Room:  /d/luoyang/lvzhulin.c

inherit  ROOM;

void  create  ()
{
	set("short",  "������");
	set("long",  @LONG
һƬ���װ�����ְ����ȵ�����Ұ֮�⣬������һƬ�������硣С
ʯ��·�������д��������ʯ�Ӽ���ϸ�ܵ���̦��͸��һ����ˬ���Խ�
���������ܡ������Ǹ�СԺ�ӡ������淢�ö��ˡ�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south"  :  __DIR__"xiaoxiang",
		"north"  :  __DIR__"lvzhuxiaoyuan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "luoyang");
	set("coor/x", -380);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}