// /d/changan/chaguan.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "��ܰ���");
	set  ("long",  @LONG
��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ�����Ű���
��һ���ſ��������˿��ˡ�һλ����������ǰ���࣬���������������衣
��ȷ�Ǹ���Ȼȥ����
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"northeast" :  __DIR__"zaoxiang",
	]));
	set("no_clean_up",  0);
	set("coor/x", -5060);
	set("coor/y", 980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
