//  Room:  /d/changan/hanguguan.c

inherit  ROOM;

void  create  ()
{
	set("short",  "���ȹ�");
	set("long",  @LONG
������ǹź��Źء���������ɽ���������򣬹�����С�����ǿ��
һ��֮�أ��ƹض������������Զ�������ɨ���£�������Ϊ���ݴˣ�
���ɹ����˿��أ���������ʤ֮������������������Ҳ���ڴ���������
���¾���ǧ�����£��������ж�������
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  __DIR__"road1",
		"west"  :  __DIR__"road2",
	]));
	set("outdoors",  "guanzhong");
	set("no_clean_up", 0);
	set("coor/x", -900);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}




