//  Room:  /d/luoyang/eastroad.c

inherit  ROOM;

void  create  ()
{
	set("short",  "��Ƚ�");
	set("long",  @LONG
���������ս�ң�������ȽֵĲ��������Ѿ��ķϵ���ֻʣ������
��һ����ĵ�����ĵ��̡�����ʯ��ͨ��ͭ��İ�������ǹ�¥����������
�����ǵĶ��š�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  __DIR__"eastgate",
		"west"  :  __DIR__"center",
		"south" :  __DIR__"huadian",
		"north" :  __DIR__"xiaojie1",
	]));
	set("objects",  ([
		__DIR__"npc/wangjiaju" : 1,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -400);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
