// Room: /d/5lt/qiuguan.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "��ë���");
	set  ("long",  @LONG
��������ë��ݣ����Ų���������Ĺ��򣬹����Ѿ�û�п��ŵĳ�
���ˣ�����վ�����������Ĺ�ս���ˡ�
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"east"  :  __DIR__"nroad3",
	]));
	set("no_fight", 1);
	set("coor/x", -160);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
