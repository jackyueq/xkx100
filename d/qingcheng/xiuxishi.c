// Room: /d/qingcheng/xiuxishi.c

inherit RESTROOM_IN;

void create()
{
	set("short", "�᷿");
	set("long", @LONG
���Ǽ�������᷿������͸���Ĵ����ú��Ĵ�ɴ���˴�룬����
�ܻ谵������������ֻ���м����һ����ʰ����������Ĵ󴲣���
�ž�������˯�������������������Ϣ�ĵط���
LONG );
	set("sleep_room", 1);
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("coor/x", -8091);
	set("coor/y", -840);
	set("coor/z", 90);
  set("door_name","����");
	set("door_dir","east");
	set("force_name","������");
  set("outroom",__DIR__"zoulang3");
  setup();
}
