//  Room:  /d/lanzhou/jincheng.c

inherit  ROOM;

void  create  ()
{
	set("short",  "���");
	set("long",  @LONG
��ǿ���������ʱ�������ǽ�ǿ���������Ƕɿ�����ս��λ�õ�
��Ҫ�Զ�������������ʷ�����������ս�۾ͷ����������
    �����м�ֻ��Ƥ����(boat)���������ڶɵģ���һ��(yell)�����
���˹�����
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south" : __DIR__"road4",
	]));
	set("outdoors", "lanzhou");
	set("no_clean_up", 0);
	set("coor/x", -9290);
	set("coor/y", 2740);
	set("coor/z", 0);
	setup();
}

void init()
{
    add_action("do_yell", "yell");
}

int do_yell()
{
	return notify_fail("��ʲô�����Ǳ߻�û�����أ�\n");
}