//  Room:  /d/luoyang/wangxiangfang.c

inherit  ROOM;

void  create  ()
{
	set("short",  "�᷿");
	set("long",  @LONG
���������ҵ��᷿�����Ŵ���һ�ȵ��ţ��������οյ���������
�£�һ����ǧ���ߵ���������Ҿ�����һ���Ƕ���ɽ�ϻ��ң�Ҳ�Ǹ�
��������ĳ��档����һ�Ŵ󴲣�������ϯ�����Ǿ��ࡣ����С���ϰ�
�Ų�ߣ����Ϲ���һ�ڵ�����
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south"  :  __DIR__"wangzhangfang",
		"east"   :  __DIR__"wanghuating",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		__DIR__"npc/wangjiajun" : 1,
	]));
	set("coor/x", -610);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
