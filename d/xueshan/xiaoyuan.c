//      xiaoyuan.c СԺ

inherit ROOM;

void create()
{
        set("short","СԺ");
        set("long",@LONG
������ѩɽ���ڵ�СԺ����ʰ���൱�ɾ�������������������ͺ�
���һ���ڰ�ʾ��ѩɽ�����֮ʢ��һ��Ҳ�����ڱ�ʾ����Ŀڸ�Ҳ
�治������Ϊ���߾��Ǹ�������
LONG );
        set("outdoors","xueshansi");
        set("exits",([
                "west" : __DIR__"guangchang",
                "north" : __DIR__"chufang",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -69990);
	set("coor/y", -19900);
	set("coor/z", 120);
	setup();
        replace_program(ROOM);
}
