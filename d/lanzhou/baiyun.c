//  Room:  /d/lanzhou/baiyun.c

inherit  ROOM;

void  create  ()
{
	set("short",  "���ƹ�");
	set("long",  @LONG
һ��ɽ��ΡȻ�������¿��������δ��ţ�������ΰ���Ŷ�����ש��
���ң��������׽�ɫ��������------���ƹۡ���ǰ�������Ҿ޻���ӳ��
ʵΪ�����������Եľ���ȥ����
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south" : __DIR__"street1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -9280);
	set("coor/y", 2710);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}