// Jay 3/17/96
inherit NPC;
string ask_li();
void create()
{
        set_name("������", ({ "ji laoren", "ji"}));
        set("gender", "����");
        set("age", 83);
        set("long", "��ͷ�׷�������һ���Ǻڵģ�������Ǹߴ�
ֻ�ǹ�������������ȫ�����ƣ�˥���Ѽ���\n");
        set("attitude", "friendly");
        set("combat_exp", 475000);
        set("shen", 4800);
        set("str", 22);
        set("int", 22);
        set("con", 22);
        set("dex", 24);
        set("max_qi", 800);
        set("max_jing", 500);
        set("neili", 900);
        set("max_neili", 900);
        set("jiali", 10);
        set_skill("changquan", 90);
        set_skill("liuhe-blade", 90);
        set_skill("cuff", 90);
        set_skill("xiaoyaoyou", 90);
        set_skill("force", 90);
        set_skill("huntian-qigong", 90);
        set_skill("blade", 90);
        set_skill("parry", 90);
        set_skill("dodge", 90);
        map_skill("force", "huntian-qigong");
        map_skill("blade", "liuhe-blade");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "liuhe-blade");
        map_skill("cuff", "changquan");
        prepare_skill("cuff", "changquan");
        set("inquiry", ([
            "������" : (: ask_li :),
            "��������" : "������������������ҵ����ơ�\n",
            "����" : "˭���Ҳ�֪������ˡ�\n",
        ]) );
        setup();
        carry_object(__DIR__"obj/bishou")->wield();
        carry_object(__DIR__"obj/yangao")->wear();
      if (clonep(this_object())) 
        carry_object(__DIR__"obj/rousisuo");
}

string ask_li()
{
    object me, ob, where;
    me=this_player();
    ob = find_living("li wenxiu");
    if (!ob) return "�⺢�ӣ���֪��������ȥ�ˣ���������\n";
    where = environment(ob);
       if (!where) return "�⺢�ӣ���֪��������ȥ�ˣ���������\n";
    return "Ŷ���⺢�Ӻ����ܵ�"+where->query("short")+"��ȥ�ˡ�";        
}
