// Room: /d/5lt/chuandashi.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "������");
	set  ("long",  @LONG
�����Ǵ�֧���Ĵ����ҡ�����ͷ�ӿ�Ų��մ��ſ��߹���ȴƳ����
���ҵĴ�ү�������㣬Ŀ�⾼����ʮ�־��衣
LONG);
	set("exits",  ([  //sizeof()  ==  3
		"north"  :  __DIR__"yuelanshi",
		"west"   :  __DIR__"czoffice",
		"east"   :  __DIR__"nroad2",
	]));
	set("no_fight", 1);
	set("coor/x", -160);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
