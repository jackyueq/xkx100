// /d/changan/eastroad2.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "�����");
	set  ("long",  @LONG
�������ڳ���������ϣ�һ����������ʯ��ֵ���������ͷ���졣
�ϱ���һ�����ӵ�Ժ�ӣ������εĴ����Ϸ�д�š�������Ժ���ĸ��̽�
���֣��Ծ����������治ʱ�ش���ѧ��������ٴ�Ķ��������ͱ�����
��֮��������һ�𡣱�����ǳ����ַ��ˡ�
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"west"  :  __DIR__"center",
		"east"  :  __DIR__"eastroad1",
		"north" :  __DIR__"club",
		"south" :  __DIR__"shuyuan",
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5030);
	set("coor/y", 1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
