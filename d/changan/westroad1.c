// /d/changan/westroad1.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "�����");
	set  ("long",  @LONG
�������ڳ���������ϣ��Ͼ���Ϊ�೯�Ŷ������ɷǱ�Ѱ�����ϱ�
�Ǳ��֣������Ǹ����ֵĿ�ջ�����Ը��ص����ǽ�����������˵Ҳ����
���ǵ��Ļ�ص㡣
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"west"  :  __DIR__"westgate",
		"east"  :  __DIR__"westroad2",
		"north" :  __DIR__"kedian",
		"south" :  __DIR__"beilin",
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5060);
	set("coor/y", 1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
