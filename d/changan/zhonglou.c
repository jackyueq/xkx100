// /d/changan/zhonglou.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "��¥");
	set  ("long",  @LONG
��¥����������һʮ���ꡣ����ʯΪ��������ľΪ��¥��¥������
����һ�ڣ����Ա�ʱ����¥��˵�����¥ǰ�Ǹ����ֵĹ㳡�����Ͽ���
�������������ı��֣���������¥ң���Ӧ��
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"down"  :  __DIR__"center",
	]));
	set("outdoors",  "changan");
	set("coor/x", -5040);
	set("coor/y", 1000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
