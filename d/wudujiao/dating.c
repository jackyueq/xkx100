// Room: /d/wudujiao/dating.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǹ����Ĵ������ߴ��������һ�˶��ϱ���������������ƽ�ս�
���ټ����������µĵط����������й�������ʥ--���ߣ�֩�룬��򼣬Ы��
��ܵĻ��񡣼�λ������������������ ��
LONG
        );
        set("valid_startroom", 1);

        set("exits", ([
                "east" : __DIR__"huayuan1",
                "south" : __DIR__"jingshi",
                "west" : __DIR__"lianwu",
                "north" : __DIR__"shufang",
        ]));
        set("objects", ([
               CLASS_D("wudujiao")+"/first": 1,
               CLASS_D("wudujiao")+"/qiyunao": 1,
               CLASS_D("wudujiao")+"/panxiuda": 1,
               CLASS_D("wudujiao")+"/cenqisi": 1,
        ]));


	set("coor/x", -44910);
	set("coor/y", -81050);
	set("coor/z", 30);
	setup();
        "/clone/board/wudu_b"->foo();
}
int valid_leave(object me, string dir)
{
        int i;
        object ob;
        me=this_player();
        if(dir=="east"||dir=="north"||dir=="south")
        {
              if ((string)me->query("family/family_name")!="�嶾��"
                 & objectp(present("qi yunao", environment(me))))
              return notify_fail("���ư�����һ�Σ���Ȼ��ס�㣬����˵������λ" +
              RANK_D->query_respect(me) + "���Ǳ��̵��ӣ����ý��뱾�̽��ء�\n");
        }
        return ::valid_leave(me, dir);
}