//  Room:  /d/luoyang/road2.c

inherit  ROOM;

void  create  ()
{
	set("short",  "��ٵ�");
	set("long",  @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�·�߻�����Щ��
������ĵ������һ����֪���������ǵ�Ͻ�ء��������ͨ�����ݵĴ��
�����������������������ǣ�����������������������ʤ�أ������¡�
���������οͺܶ࣬·�߲ݵ��Ѿ����ȵ��൱ƽ�ˡ�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"      :  __DIR__"hulaoguan",
		"west"      :  __DIR__"eastgate",
		"south"     :  __DIR__"road7",
		"northeast" :  __DIR__"baimasi",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -200);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
