// /d/changan/eastroad1.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "�����");
	set  ("long",  @LONG
�����ڶ�����ϣ����ż�ʵ����ʯ����档�����Ƕ����ţ�������
���سǹٱ���ߺ���������������ʵĶ�����������һ���ϱ��Ǹ�С��
�ӣ�ר����һЩ����Ʒ�������ǿ�յأ�����һЩ���ܡ�
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"west"  :  __DIR__"eastroad2",
		"east"  :  __DIR__"eastgate",
		"north" :  __DIR__"huachang",
		"south" :  __DIR__"xiaopu",
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5020);
	set("coor/y", 1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
