// Room: /d/songshan/xiuxishi.c
// Last Modified by winder on Aug. 5 2001

inherit RESTROOM_IN;
void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
���Ǽ�������᷿������ɽ������Ϣ��ӵĵط�����Ϊ�Ŵ������
�ţ���������谵�����￿�����������Σ���߿�ǽ����һ����ʰ����
������Ĵ󴲣����ž�������˯����
LONG );

        set("sleep_room", 1);
        set("no_clean_up", 0);
        set("no_fight", 1);
	set("coor/x", 10);
	set("coor/y", 910);
	set("coor/z", 90);
  set("door_name","��");
	set("door_dir","west");
	set("force_name","��Ӣ��");
  set("outroom",__DIR__"eastpath2");
	setup();
}
