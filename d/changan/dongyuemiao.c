// /d/changan/dongyuemiao.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "������");
	set  ("long",  @LONG
��������̩ɽ������������Ϊɽ�����飬��˽�����롣������
�����������ꡣ����ΰ׳�ۣ�������ǽ�ϻ��Ų���¥����Ů��Զ����
ͨ�ڽ����֮�ڻ��ɱȣ�����Ԫ�����ϡ�
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"northwest" :  __DIR__"zaoxiang",
	]));
	set("no_clean_up",  0);
	setup();
	replace_program(ROOM);
}

