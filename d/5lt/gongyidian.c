// Room: /d/5lt/gongyidian.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "��乤��Ʒ��");
	set  ("long",  @LONG
����һ����ɫ�������乤��Ʒ�̵ꡣ���ڰ������Ϻõ���̴ľ��
�ߣ�����������ŵ����ղصĸ���������Ʒ��ǽ��������˵����Լ�
���Ƶ�Ascii������
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"south"  :  __DIR__"wroad1",
	]));
	set("objects",  ([
		__DIR__"npc/xiyi": 1,
	]));
	set("no_fight", "1");
	set("coor/x", -160);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
