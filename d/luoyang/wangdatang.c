//  Room:  /d/luoyang/wangdatang.c

inherit  ROOM;

void  create  ()
{
	set("short",  "����");
	set("long",  @LONG
һ�������ţ�ֻ����������һ�������ң�д�š�������Ϊ���ĸ�
���֣���������Ǻ���ʡ��Ѳ��ĳ�ˡ��������ҵ�������ֻ�书�ϵ���
�������ġ�����Ҳ������ӭ������ĵط����������ߣ���װ�ε�ʮ�ֻ�
��
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north"  :  __DIR__"wanghuating",
		"south"  :  __DIR__"wangdayuan",
		"west"   :  __DIR__"wangzhangfang",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		__DIR__"npc/wang" : 1,
	]));
	set("coor/x", -600);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}