//  Room:  /d/5lt/fantexi.c

inherit  ROOM;

void  create  ()
{
	set("short",  "����Ϫ");
	set("long",  @LONG
������Ǵ�˵�еķ���Ϫ�ˡ���һ��������СϪ��������������
���ʵ�СϪ��������ˮ˿һ���ӿ��ָ�����������ƵĴ�������չ������
��Ȫˮ����һ���������
LONG);
	set("exits",  ([
		"northeast"  :  __DIR__"kongdi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "5lt");
	set("coor/x", -195);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}