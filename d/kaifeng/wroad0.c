inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
���⸮���������Ҫ��ͨҪ�����ֵ����ߵ�������������
��������С�̷������ŵ�������ߺ�ȡ��˵��򶫾��������
�ķ����أ����򱱹�ȥ��Զ�����ܼ�������۵Ĵ����ˡ�
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
  		"north" : __DIR__"wroad1",
  		"eastup" : __DIR__"fangsheng",
	]));
        set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
