//  Room:  /d/luoyang/wanglianwu.c

inherit  ROOM;

void  create  ()
{
	set("short",  "������");
	set("long",  @LONG
��˵����������ԥ�����书��������������������������ġ�����
������Ҳֻ������һ����Ѱ�������Ӷ��ѣ�Ψһͻ���ģ������Ƕ�ǽ��
������һ�ڵ������ˡ�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south"  :  __DIR__"wanghuating",
	]));
	set("no_clean_up", 0);
	set("coor/x", -600);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}