//  Room:  /d/luoyang/xiaojiudian.c

inherit  ROOM;

void  create  ()
{
	set("short",  "����");
	set("long",  @LONG
�����Ǹ�С�������߰����������ڵ��ж����ӡ�������Щ��ƺ���
Ѽ��ˮ���㿴��һ��θ�ڶ�û�С������ǿ����㣬һ��Ҫʹ����һ�٣�
���߶����Ӻݳ���һ����ǧ�����ӣ����������߰ɡ�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south" :  __DIR__"xiaojie1",
	]));
	set("objects",  ([
		__DIR__"npc/wulai" : 3,
	]));
	set("coor/x", -400);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
