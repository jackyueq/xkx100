//  Room:  /d/luoyang/wangdayuan.c

inherit  ROOM;

void  create  ()
{
	set("short",  "��Ժ");
	set("long",  @LONG
���߽����Ҵ�Ժ��Ժ�����ż�����÷��֦������򰾢��Ժ������С
ͥԺ�ڣ��ٲ������������ı�־������ͦ�����ĵ����Ժ����ͣ�˲���
����ÿһƥ���ڶ��ǰ����������������ҡ������������ƹ��ǲ�����
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north"  :  __DIR__"wangdatang",
		"west"   :  __DIR__"wangxiaoyuan",
		"out"    :  __DIR__"wanggate",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -600);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}