//  Room:  /d/5lt/kongdi.c

inherit  ROOM;

void  create  ()
{
	set("short",  "�յ�");
	set("long",  @LONG
������Ϫ��һ��ƽ̹�Ŀյء��յص����˴��û��ʲô��Ͼ��ֻ��
��΢ƽ��һ�£�����Щ�̲ݡ�����ĳ����Ǿ����������ˣ��
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"southwest"  :  __DIR__"fantexi",
		"north"      :  __DIR__"wroad4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "5lt");
	set("coor/x", -190);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}