// /d/changan/kuixinglou.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "����¥");
	set  ("long",  @LONG
�����������ϵ�һ����¥����Ŀ���������Կ����ϱ����������ɽ��
�Ա߼����ٱ�������Ϣ�����������Ǿ����صأ�����û��ǸϿ��뿪��
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"down"  :  __DIR__"southgate",
	]));
	set("objects",  ([  //sizeof()  ==  4
		"/d/city/npc/wujiang" : random(3),
		"/d/city/npc/bing" : random(3),
	]));
	set("outdoors",  "changan");
	set("coor/x", -5040);
	set("coor/y", 970);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
