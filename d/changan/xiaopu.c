// /d/changan/xiaopu.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "С����");
	set  ("long",  @LONG
����һ��ר�����μ���Ʒ��С���ӡ����˳�����������Ʒ��˵��
��ȥ��......һ����ɩ��վ����ǰ���ο��������⡣
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"north"  :  __DIR__"eastroad1",
	]));
	set("objects",  ([  //sizeof()  ==  4
		__DIR__"npc/dasao": 1,
	]));
	set("coor/x", -5020);
	set("coor/y", 990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
